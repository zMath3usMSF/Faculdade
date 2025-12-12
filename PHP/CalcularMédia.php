<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Calcular Média em PHP.</title>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js" integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI" crossorigin="anonymous"></script>
    <style>
        body{
            text-align: center;
        }
    </style>
    </head>
    <body class="text-justify">
        <h1><?php
            $notas = [5.0, 9.0, 4.5, 9.5];

            $media=0;
            foreach($notas as $nota)
            {
                $media+=$nota;
            }
            $media = $media / count($notas);
            echo "Sua nota foi: " . $media . "<br>";
            if($media >= 5)
            {
                echo "Parabéns, você foi aprovado!";
            }else{
                echo "Você foi reprovado, estude mais.";
            }
        ?></h1>
    </body>
</html>