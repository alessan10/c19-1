package com.auth.jwt.security;


import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Value;
import io.jsonwebtoken.*;
import org.springframework.stereotype.Component;

import java.util.Date;

/*Questa classe ci serve per gestire i token:
 1) generare un token
 2) estrarre l’username dal token
 3) fare la validazione del token.
*/
@Component
public class JwtUtils {
    private static final Logger logger = LoggerFactory.getLogger(JwtUtils.class);

    @Value("${jwtSecret}")
    private String jwtSecret;

    @Value("${jwtExpirationMs}")
    private int jwtExpirationMs;

    public String generateJwtToken(String username) {

        return Jwts.builder()
                .setSubject(username)
                .setIssuedAt(new Date())
                .setExpiration(new Date((new Date()).getTime() + jwtExpirationMs))
                .signWith(SignatureAlgorithm.HS512, jwtSecret)
                .compact(); // Builds the JWT and serializes it to a compact, URL-safe string
    }

    // Estrai lo username dal token (dal campo subject)
    public String getUserNameFromJwtToken(String token) {
        return Jwts.parser().setSigningKey(jwtSecret).parseClaimsJws(token).getBody().getSubject();
    }

    // Verifica se il token è valido
    public boolean validateJwtToken(String authToken) {
        try {

            // Esegue il parsing del token mediante la chiave segreta usata in fase di generazione del token
            // Se il sender ha modificato il token, il server non sarà in grado di farne il parsing
            Jwts.parser().setSigningKey(jwtSecret).parseClaimsJws(authToken);
            return true;
        } catch (Exception e) {
            logger.error("Unable to validate JWT token: {}", e.getMessage());
        }
        return false;
    }
}
