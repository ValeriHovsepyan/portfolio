package com.example.chat.controller;

import com.example.chat.model.Message;
import com.example.chat.model.MessageResponse;
import com.example.chat.service.MessageService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/messages")
public class MessageController
{
    @Autowired
    private MessageService messageService;

    @PostMapping("send/private")
    public void sendPrivateMessage(@RequestBody Message message)
    {
        messageService.sendPrivateMessage(message.getSender(), message.getReceiver(), message.getContent());
    }

    @PostMapping("send/group")
    public void sendGroupMessage(@RequestBody Message message)
    {
        messageService.sendGroupMessage(message.getSender(), message.getGroupName(), message.getContent());
    }

    @PostMapping("send/public")
    public void sendPublicMessage(@RequestBody Message message)
    {
        messageService.sendPublicMessage(message.getSender(), message.getContent());
    }

    @GetMapping("user/{username}")
    public List<MessageResponse> getUserMessages(@PathVariable String username)
    {
        return messageService.getMessagesForUser(username);
    }

    @GetMapping("group/{group}")
    public List<MessageResponse> getGroupMessages(@PathVariable String group)
    {
        return messageService.getMessagesForGroup(group);
    }

    @GetMapping("public")
    public List<MessageResponse> getPublicMessages()
    {
        return messageService.getPublicMessages();
    }
}
