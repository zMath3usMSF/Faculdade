<?php

//Definindo os parâmetros de conexão:
define('HOST', '127.0.0.1');
define('PORT', '5432');
define('DBNAME', 'test');
define('USER', 'user');
define('PASSWORD', 'psswd');

//try e catch para tratamento de exceção
try {

  //Estabelecendo a conexão com o banco:
  $dsn = new PDO("pgsql:host=". HOST . ";port=".PORT.";dbname=" . DBNAME .";user=" . USER . ";password=" . PASSWORD) ;

} catch (PDOException $e) {
  echo 'A conexão falhou e retornou a seguinte mensagem de erro: ' .$e->getMessage();
}

$dsn = null;

?>