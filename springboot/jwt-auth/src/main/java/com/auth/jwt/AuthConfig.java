package com.auth.jwt;

import com.auth.jwt.security.AuthTokenFilter;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpMethod;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.config.http.SessionCreationPolicy;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;


@Configuration
@EnableWebSecurity
public class AuthConfig extends WebSecurityConfigurerAdapter {

    @Autowired
    AuthUserDetailsService userDetailsService;

    @Bean
    public AuthTokenFilter authenticationJwtTokenFilter() {
        return new AuthTokenFilter();
    }

    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth.userDetailsService(userDetailsService);
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
                //.httpBasic()
                //.and()
                // STATELESS session
                .sessionManagement().sessionCreationPolicy(SessionCreationPolicy.STATELESS).and()
                .authorizeRequests()
                .antMatchers("/user/register").permitAll() // Consenti a tutti l'accesso all'endpoint /user/register
                .antMatchers("/user/login/**").permitAll() // Consenti a tutti l'accesso all'endpoint /user/login
                .antMatchers("/user/all").hasAuthority("ADMIN") // Consenti soltanto agli utenti con ruolo ADMIN l'accesso a /user/all
                .antMatchers(HttpMethod.DELETE, "/user/{id}").hasAuthority("ADMIN") // Consenti soltanto agli utenti con ruolo ADMIN la rimozione degli utenti
                /*
                .antMatchers(HttpMethod.GET, "/product/*").permitAll()  // Consenti a tutti l'operazione di GET all'endpoint /product
                .antMatchers(HttpMethod.POST, "/product/add").hasAuthority("ADMIN")
                .antMatchers(HttpMethod.DELETE, "/product/{id}").hasAuthority("ADMIN")
                .antMatchers(HttpMethod.DELETE, "/product/{id}").hasAuthority("ADMIN")
                .antMatchers(HttpMethod.DELETE, "/order/{id}").hasAuthority("ADMIN")
                .antMatchers(HttpMethod.GET, "/order/all").hasAuthority("ADMIN")
                */
                .anyRequest().authenticated() // Tutte le altre richieste devono essere autenticate
                .and()
                .csrf().disable(); // Nel caso di REST API stateless, la protezione Cross-Site-Request-Forgery non serve

        // Ogni richiesta in ingresso deve essere prima filtrata per la validazione del token
        http.addFilterBefore(authenticationJwtTokenFilter(), UsernamePasswordAuthenticationFilter.class);

    }
}

