<?php

require_once "PáginaLoginConexão.php";

/*** CONSULTA NO BANCO DE DADOS ***/
$instrucaoSQL = "
    SELECT 
        id_cliente,
        nome_cliente,
        cpf_cliente,
        email_cliente,
        data_nascimento_cliente
    FROM cliente
";

$resultSet = $dsn->query($instrucaoSQL);

while ($row = $resultSet->fetch(PDO::FETCH_ASSOC)) {

    echo $row['id_cliente'] . "<br>";
    echo $row['nome_cliente'] . "<br>";

    echo preg_replace(
        "/(\d{3})(\d{3})(\d{3})(\d{2})/",
        "$1.$2.$3-$4",
        $row['cpf_cliente']
    ) . "<br>";

    echo $row['email_cliente'] . "<br>";

    echo date(
        'd/m/Y',
        strtotime($row['data_nascimento_cliente'])
    ) . "<hr>";
}
?>
