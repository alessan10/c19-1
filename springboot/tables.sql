CREATE TABLE user (
		id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    email VARCHAR(50) NOT NULL UNIQUE,
		name VARCHAR(50) NOT NULL,
    password VARCHAR(255) NOT NULL
    )ENGINE = 'InnoDB';

CREATE TABLE user_roles (
		user_id INT NOT NULL,,
		roles varchar(255),		

		FOREIGN KEY(user_id) 
				REFERENCES user(id) 
				ON UPDATE CASCADE 
				ON DELETE CASCADE			
		)ENGINE = 'InnoDB';
