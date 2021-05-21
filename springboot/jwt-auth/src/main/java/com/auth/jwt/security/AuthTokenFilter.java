package com.auth.jwt.security;

import com.auth.jwt.AuthUserDetailsService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.web.authentication.WebAuthenticationDetailsSource;
import org.springframework.util.StringUtils;
import org.springframework.web.filter.OncePerRequestFilter;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/*
Creiamo una classe che ci permette di filtrare la richiesta che arriva al nostro sistema.
In particolare questi filtri dovranno:
 1) estrarre il token dall’header dalla richiesta,
 2) fare la validazione del token
 3) se la validazione del token è andata a buon fine, ricaviamo l’username dal token, vediamo nel
   db le informazioni dell’utente quali  la password e i ruoli di quell’utente.
A quel punto procediamo con la creazione di  un oggetto particolare riconosciuto da Spring
 per procedere con la validazioni delle credenziali e fare un confronto tra username e password
 e poi fare un controllo sulle autorizzazioni in base ai ruoli che ha l’utente.

La cosa importante è che questo filtro deve essere applicato ad ogni richiesta.

 */
public class AuthTokenFilter extends OncePerRequestFilter {
    @Autowired
    private JwtUtils jwtUtils;

    @Autowired
    private AuthUserDetailsService userDetailsService;

    private static final Logger logger = LoggerFactory.getLogger(AuthTokenFilter.class);

    @Override
    protected void doFilterInternal(HttpServletRequest request, HttpServletResponse response, FilterChain filterChain)
            throws ServletException, IOException {
        try {
            // Estrai il token dall'Header "Authorization" della richiesta
            String jwt = parseJwt(request);
            if (jwt != null && jwtUtils.validateJwtToken(jwt)) {
                // Estrai lo username dal token
                String username = jwtUtils.getUserNameFromJwtToken(jwt);

                // Verifica se nel database esiste un utente con questo username
                UserDetails userDetails = userDetailsService.loadUserByUsername(username);

                // Costruisci
                UsernamePasswordAuthenticationToken authentication = new UsernamePasswordAuthenticationToken(
                        userDetails, null, userDetails.getAuthorities());
                authentication.setDetails(new WebAuthenticationDetailsSource().buildDetails(request));

                // Set the Authentication object into the current SecurityContext
                // used by the framework to hold the currently logged-in user
                SecurityContextHolder.getContext().setAuthentication(authentication);
            }
        } catch (Exception e) {
            logger.error("Cannot set user authentication: {}", e);
        }

        filterChain.doFilter(request, response);
    }

    // Estrazione del JWT token dall'Header "Authorization"
    private String parseJwt(HttpServletRequest request) {
        String headerAuth = request.getHeader("Authorization");

        // Rimuovi "Bearer "
        if (StringUtils.hasText(headerAuth) && headerAuth.startsWith("Bearer ")) {
            return headerAuth.substring(7, headerAuth.length());
        }

        return null;
    }
}

