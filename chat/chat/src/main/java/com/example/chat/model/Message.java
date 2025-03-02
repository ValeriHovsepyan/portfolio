package com.example.chat.model;

import jakarta.persistence.*;
import org.springframework.security.core.parameters.P;

import java.time.LocalDateTime;
import java.util.Set;

@Entity
@Table(name = "messages")
public class Message
{
    @Id
    @GeneratedValue
    private long id;

    private String sender;

    private String receiver;

    private String groupName;

    private String content;

    public Message() {}

    public Message(String sender, String receiver, String group, String content)
    {
        this.sender = sender;
        this.receiver = receiver;
        this.groupName = group;
        this.content = content;
    }

    public Long getId()
    {
        return id;
    }

    public void setId(Long id)
    {
        this.id = id;
    }

    public String getSender()
    {
        return sender;
    }

    public void setSender(String sender)
    {
        this.sender = sender;
    }

    public String getReceiver()
    {
        return receiver;
    }

    public void setReceiver(String receiver)
    {
        this.receiver = receiver;
    }

    public String getGroupName()
    {
        return groupName;
    }

    public void setGroup(String group)
    {
        this.groupName = group;
    }

    public String getContent()
    {
        return content;
    }

    public void setContent(String content)
    {
        this.content = content;
    }

    @Override
    public String toString()
    {
        return "Message{" +
                "id=" + id +
                ", sender='" + sender + '\'' +
                ", receiver='" + receiver + '\'' +
                ", groupName='" + groupName + '\'' +
                ", content='" + content + '\'' +
                '}';
    }
}
