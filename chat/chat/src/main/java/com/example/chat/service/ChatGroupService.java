package com.example.chat.service;

import com.example.chat.model.ChatGroup;
import com.example.chat.model.GroupCreateRequest;
import com.example.chat.model.User;
import com.example.chat.repo.ChatGroupRepo;
import com.example.chat.repo.UserRepo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

@Service
public class ChatGroupService
{
    @Autowired
    private ChatGroupRepo chatGroupRepo;

    @Autowired
    private UserRepo userRepo;

    public void createGroup(GroupCreateRequest groupCreateRequest)
    {
        ChatGroup group = new ChatGroup();
        group.setName(groupCreateRequest.getName());

        Set<User> members = new HashSet<>();
        for (String username : groupCreateRequest.getMemberUsernames()) {
            User user = userRepo.findByUsername(username)
                    .orElseThrow(() -> new RuntimeException("User not found: " + username));
            members.add(user);
        }

        group.setMembers(members);

        chatGroupRepo.save(group);
    }

    public List<GroupCreateRequest> getGroups()
    {
        List<ChatGroup> groups = chatGroupRepo.findAll();
        List<GroupCreateRequest> groupCreateRequests = new ArrayList<>();
        for (ChatGroup group : groups)
        {
            Set<String> usernames = new HashSet<>();
            for (User user : group.getMembers())
            {
                usernames.add(user.getUsername());
            }
            groupCreateRequests.add(new GroupCreateRequest(group.getName(), usernames));
        }
        return groupCreateRequests;
    }
}
