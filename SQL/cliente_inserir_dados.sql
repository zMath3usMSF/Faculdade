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