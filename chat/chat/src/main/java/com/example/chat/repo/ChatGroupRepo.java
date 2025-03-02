package com.example.chat.repo;

import com.example.chat.model.ChatGroup;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface ChatGroupRepo extends JpaRepository<ChatGroup, Long>
{
    Optional<ChatGroup> findByName(String name);
}
