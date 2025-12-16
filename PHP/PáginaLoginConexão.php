<?php

define('HOST', 'localhost');
define('PORT', '5432');
define('DBNAME', 'test_02');
define('USER', 'postgres');
define('PASSWORD', '1234');

try{
    $dsn = new PDO("pgsql:host=" . HOST . 
                    ";port=" . PORT .
                    ";dbname=" . DBNAME,
                    USER,
                    PASSWORD);

                    echo "Conexão com o banco de dados foi estabelecida com sucesso!<br>";
} catch (PDOException $e){

    echo "A conexão falhou e retornou a seguinte mensagem de erro: " . $e->getMessage();
    exit;
}
?>