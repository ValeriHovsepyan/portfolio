package com.example.chat.controller;

import com.example.chat.model.User;
import com.example.chat.service.AuthService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/auth")
public class AuthController
{
    @Autowired
    private AuthService authService;

    @PostMapping("/register")
    public void registerUser(@RequestBody User user)
    {
        authService.registerUser(user);
    }

    @PutMapping("/login")
    public String login(@RequestBody User user)
    {
        return authService.verifyUser(user.getUsername(), user.getPassword());
    }

    @GetMapping("/users")
    public List<User> getUsers()
    {
        return authService.getUsers();
    }
}
