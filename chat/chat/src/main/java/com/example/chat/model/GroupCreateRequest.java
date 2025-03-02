package com.example.chat.model;

import org.apache.kafka.common.protocol.types.Field;

import java.util.HashSet;
import java.util.Set;

public class GroupCreateRequest
{
    private String name;
    private Set<String> memberUsernames;

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public Set<String> getMemberUsernames()
    {
        return memberUsernames;
    }

    public void setMemberUsernames(Set<String> memberUsernames)
    {
        this.memberUsernames = memberUsernames;
    }

    public GroupCreateRequest(String name, Set<String> memberUsernames)
    {
        this.name = name;
        this.memberUsernames = memberUsernames;
    }
}
