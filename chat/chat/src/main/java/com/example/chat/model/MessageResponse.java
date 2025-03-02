package com.example.chat.model;

public class MessageResponse
{
    private String sender;
    private String content;

    public String getContent()
    {
        return content;
    }

    public String getSender()
    {
        return sender;
    }

    public void setContent(String content)
    {
        this.content = content;
    }

    public void setSender(String sender)
    {
        this.sender = sender;
    }

    public MessageResponse(String content, String sender)
    {
        this.content = content;
        this.sender = sender;
    }

    public MessageResponse()
    {

    }
}
