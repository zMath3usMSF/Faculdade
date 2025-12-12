<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Exemplo de Script PHP.</title>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js" integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI" crossorigin="anonymous"></script>
    <style>
        body{
            text-align: center;
        }
    </style>
    </head>
    <body class="text-justify">
        <h1><b>Exemplo de Script PHP</b><br><br></h1>

        <h4>Exemplo de Escrita de Texto usando PHP</h4>
        <p class="lead"><?php echo "Olá Mundo"; ?></p>

        <h4>Exemplo de Declaração e Soma de Variáveis usando PHP</h4>
        <?php
            $var1 = 13;
            echo "Valor da variável var1: " . $var1 . "<br>";
            $var2 = 12;
            echo "Valor da variável var2: " . $var2 . "<br>";
            echo "Valor da soma das duas variáveis é: " . $var1 + $var2 . "<br>";
        ?>
    </body>
</html>