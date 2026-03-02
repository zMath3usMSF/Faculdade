SELECT * FROM CLIENTES

ALTER TABLE clientes ADD COLUMN endereco VARCHAR(200);

INSERT INTO CLIENTES (NOME, IDADE) VALUES ('CLIENTE NOVO1', 67);

INSERT INTO CLIENTES (NOME, IDADE) VALUES ('CLIENTE NOVO2', NULL);

ALTER TABLE clientes ALTER COLUMN idade SET NOT NULL;

ALTER TABLE  clientes RENAME COLUMN endereco TO endereco_residencial;

ALTER TABLE clientes DROP COLUMN endereco_residencial;

ALTER TABLE clientes ADD COLUMN idreg integer references regiao(id)

UPDATE CLIENTES SET idreg = 1

DROP TABLE pedidos;

DROP TABLE regiao CASCADE;

DROP TABLE clientes;

DROP TABLE regiao;