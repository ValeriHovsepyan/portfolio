package com.example.chat.service;

import com.example.chat.model.ChatGroup;
import com.example.chat.model.Message;
import com.example.chat.model.MessageResponse;
import com.example.chat.model.User;
import com.example.chat.repo.ChatGroupRepo;
import com.example.chat.repo.MessageRepo;
import com.example.chat.repo.UserRepo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class MessageService
{
    @Autowired
    private MessageRepo messageRepo;

    @Autowired
    private UserRepo userRepo;

    @Autowired
    private ChatGroupRepo chatGroupRepo;

    public void sendPrivateMessage(String senderUsername, String receiverUsername, String content)
    {
        User sender = userRepo.findByUsername(senderUsername).orElse(null);
        User receiver = userRepo.findByUsername(receiverUsername).orElse(null);

        System.out.println(sender.getUsername());
        System.out.println(receiver.getUsername());

        if (sender == null || receiver == null)
            throw new RuntimeException("Sender or Reciever not found");

        Message message = new Message(sender.getUsername(), receiver.getUsername(), null, content);
        messageRepo.save(message);
    }

    public void sendGroupMessage(String senderUsername, String receiverUsername, String content)
    {
        User sender = userRepo.findByUsername(senderUsername).orElse(null);
        ChatGroup group = chatGroupRepo.findByName(receiverUsername).orElse(null);
        if (sender == null && group == null)
            throw new RuntimeException("Sender or Group not found");

        Message message = new Message(sender.getUsername(), null, group.getName(), content);
        messageRepo.save(message);
    }

    public void sendPublicMessage(String senderUsername, String content)
    {
        User sender = userRepo.findByUsername(senderUsername).orElse(null);

        if (sender == null)
            throw new RuntimeException("Sender not found");

        Message message = new Message(sender.getUsername(), null, null, content);
        messageRepo.save(message);
    }

    public List<MessageResponse> getMessagesForUser(String username)
    {
        User receiver = userRepo.findByUsername(username).orElse(null);
        if (receiver == null)
            throw new RuntimeException("Receiver not found");
        List<Message> messages = messageRepo.findByReceiver(receiver.getUsername());
        List<MessageResponse> messageResponses = new ArrayList<>();
        for (Message message : messages)
        {
            messageResponses.add(new MessageResponse(message.getContent(), message.getSender()));
        }
        return messageResponses;
    }

    public List<MessageResponse> getMessagesForGroup(String groupName)
    {
        ChatGroup group = chatGroupRepo.findByName(groupName).orElse(null);
        if (group == null)
            throw new RuntimeException("Group not found");
        List<Message> messages = messageRepo.findByGroupName(group.getName());
        List<MessageResponse> messageResponses = new ArrayList<>();
        for (Message message : messages)
        {
            messageResponses.add(new MessageResponse(message.getContent(), message.getSender()));
        }
        return messageResponses;
    }

    public List<MessageResponse> getPublicMessages()
    {
        List<Message> messages = messageRepo.findByReceiver(null);
        List<MessageResponse> messageResponses = new ArrayList<>();
        for (Message message : messages)
        {
            messageResponses.add(new MessageResponse(message.getContent(), message.getSender()));
        }
        return messageResponses;
    }
}
