<?php

require_once "PáginaLoginConexão.php";

$login = $_POST['user'];
$pswd = $_POST['password'];
$instrucaoSQL = "Select * From Usuario Where login = '$login' And password = '$pswd'";
$result = pgsql_query( $instrucaoSQL ) or die(' Ocorreu um erro na execução da instrução: ' . $instrucaoSQL . ' ' .pgsql_query() );
?>