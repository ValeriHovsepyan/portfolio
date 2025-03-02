package com.example.chat.model;

import jakarta.persistence.*;
import java.util.HashSet;
import java.util.Set;

@Entity
@Table(name = "chatGroup")
public class ChatGroup
{
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;

    @ManyToMany
    @JoinTable(
            name = "group_users",
            joinColumns = @JoinColumn(name = "group_id"),
            inverseJoinColumns = @JoinColumn(name = "user_id")
    )
    private Set<User> members = new HashSet<>();

    public ChatGroup() {}

    public ChatGroup(String name)
    {
        this.name = name;
    }

    public ChatGroup(String name, Set<User> members)
    {
        this.name = name;
        this.members = members;
    }

    public Long getId()
    {
        return id;
    }

    public void setId(Long id)
    {
        this.id = id;
    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public Set<User> getMembers()
    {
        return members;
    }

    @Override
    public String toString()
    {
        return "ChatGroup{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", members=" + members +
                '}';
    }

    public void setMembers(Set<User> members)
    {
        this.members = members;
    }
}
