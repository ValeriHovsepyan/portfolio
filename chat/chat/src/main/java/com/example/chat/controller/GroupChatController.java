package com.example.chat.controller;

import com.example.chat.model.ChatGroup;
import com.example.chat.model.GroupCreateRequest;
import com.example.chat.service.ChatGroupService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/group")
public class GroupChatController
{
    @Autowired
    ChatGroupService chatGroupService;

    @PostMapping("createGroup")
    public void createGroup(@RequestBody GroupCreateRequest groupCreateRequest)
    {
        chatGroupService.createGroup(groupCreateRequest);
    }

    @GetMapping("getGroups")
    public List<GroupCreateRequest> getGroups()
    {
        return chatGroupService.getGroups();
    }
}
