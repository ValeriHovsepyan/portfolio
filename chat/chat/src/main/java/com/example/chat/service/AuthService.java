package com.example.chat.service;

import com.example.chat.model.User;
import com.example.chat.repo.UserRepo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class AuthService
{
    @Autowired
    UserRepo userRepo;

    @Autowired
    AuthenticationManager authManager;

    private BCryptPasswordEncoder encoder = new BCryptPasswordEncoder(10);

    public void registerUser(User user)
    {
        user.setPassword(encoder.encode(user.getPassword()));
        userRepo.save(user);
    }

    public String verifyUser(String username, String password)
    {
        Authentication auth = authManager.authenticate(new UsernamePasswordAuthenticationToken(username, password));
        return auth.isAuthenticated() ? "Successful login" : "Wrong username or password";
    }

    public List<User> getUsers()
    {
        return userRepo.findAll();
    }
}
