CREATE TABLE customers (
	customer_id int NOT NULL GENERATED ALWAYS AS IDENTITY (INCREMENT 1 START 1) PRIMARY KEY,
	first_name varchar(30) NOT NULL,
	last_name varchar(30) NOT NULL,
	email varchar(50) NOT NULL,
	phone char(10) NOT NULL,
	addr1 varchar(50) NOT NULL,
	addr2 varchar(40),
	city varchar(40) NOT NULL,
	state char(2) NOT NULL,
	zip char(9) NOT NULL
);

CREATE TABLE models (
	model_id int NOT NULL GENERATED ALWAYS AS IDENTITY (INCREMENT 1 START 1) PRIMARY KEY,
	model_name varchar(255),
	range int,
	price money
);

CREATE TABLE colors (
	color_id int NOT NULL GENERATED ALWAYS AS IDENTITY (INCREMENT 1 START 1) PRIMARY KEY,
	color_name varchar(50),
	upcharge money,
	int_ext char(1)
);

CREATE TABLE electronics (
	electronics_id int NOT NULL GENERATED ALWAYS AS IDENTITY (INCREMENT 1 START 1) PRIMARY KEY,
	power_name varchar(50),
	upcharge money
);

CREATE TABLE drive_systems (
	drive_id int NOT NULL GENERATED ALWAYS AS IDENTITY (INCREMENT 1 START 1) PRIMARY KEY,
	drive_name varchar(50),
	upcharge money
);

CREATE TABLE orders (
	order_id int NOT NULL GENERATED ALWAYS AS IDENTITY (INCREMENT 1 START 1) PRIMARY KEY,
	customer_id int NOT NULL REFERENCES customers(customer_id),
	order_date date NOT NULL,
	model_id int NOT NULL REFERENCES models(model_id),
	ext_color_id int NOT NULL REFERENCES colors(color_id),
	color_id int NOT NULL REFERENCES colors(color_id),
	electronics_id int NOT NULL REFERENCES electronics(electronics_id),
	drive_id int NOT NULL REFERENCES drive_systems(drive_id),
	total_price money NOT NULL,
	deposit money
);

CREATE TABLE other_options (
	option_id int NOT NULL GENERATED ALWAYS AS IDENTITY (INCREMENT 1 START 1) PRIMARY KEY,
	option_name varchar(50),
	upcharge money,
	description text
);

CREATE TABLE other_options_added (
	ooa_id int NOT NULL GENERATED ALWAYS AS IDENTITY (INCREMENT 1 START 1) PRIMARY KEY,
	order_id int NOT NULL REFERENCES orders(order_id),
	option_id int NOT NULL REFERENCES other_options(option_id)
);