package com.auth.jwt.controller;

import com.auth.jwt.entity.User;
import com.auth.jwt.service.AuthUserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.util.Optional;

@Controller
@RequestMapping(path = "/user" )
public class UserController {

    @Autowired
    AuthUserService userDetailsService;

    //POST http://localhost:8080/user/register
    @PostMapping(path = "/register")
    public @ResponseBody
    User register(@RequestBody User user) {
        return userDetailsService.addUser(user);

    }

    //GET http://localhost:8080/user/all
    @GetMapping(path = "/all")
    public @ResponseBody Iterable<User> getAll() {
        return userDetailsService.getAllUsers();
    }

    @PostMapping(path = "/login")
    public @ResponseBody String login(@RequestBody User user) {
        return userDetailsService.login(user);
    }

    //GET http://localhost:8080/user/1
    @GetMapping(path = "/{email}")
    public @ResponseBody
    Optional<User> getUser(Authentication auth, @PathVariable String email) {
        if (email.equalsIgnoreCase(auth.getName()))
            return userDetailsService.getByEmail(email);
        else return Optional.empty();
    }

    //DELETE http://localhost:8080/user/1
    @DeleteMapping(path = "/{id}")
    public @ResponseBody String deleteUser (@PathVariable Integer id) {
        return userDetailsService.deleteUser(id);
    }

}
