CREATE TABLE clientes(
	id SERIAL PRIMARY KEY,
	nome VARCHAR(100),
	email VARCHAR(100) UNIQUE,
	idade INT,
	data_criacao TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE pedidos(
	id SERIAL PRIMARY KEY,
	cliente_id INT REFERENCES clientes(id),
	data_pedido TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
	total NUMERIC(10, 2)
);

CREATE TABLE regiao(
	id INT PRIMARY KEY,
	nome VARCHAR(30)
)

INSERT INTO clientes (nome, email, idade) VALUES
('João Silva', 'joao.silva@example.com', 30),
('Maria Souza', 'maria.souza@example.com', 25);

SELECT * FROM CLIENTES

INSERT INTO pedidos (cliente_id, total) VALUES
(1, 150.00),
(1, 200.00),
(2, 300.00);

SELECT * FROM PEDIDOS

INSERT INTO regiao VALUES
(1, 'Norte'),
(2, 'Sul');

SELECT * FROM REGIAO