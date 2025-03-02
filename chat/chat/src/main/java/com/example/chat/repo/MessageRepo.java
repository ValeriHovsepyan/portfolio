package com.example.chat.repo;

import com.example.chat.model.ChatGroup;
import com.example.chat.model.Message;
import com.example.chat.model.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface MessageRepo extends JpaRepository<Message, Long>
{
    List<Message> findBySender(String sender);
    List<Message> findByReceiver(String receiver);
    List<Message> findByGroupName(String groupName);
    List<Message> findByReceiverIsNull();
}
