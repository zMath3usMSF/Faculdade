<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Exemplo de Exibição de Média em PHP</title>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js" integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI" crossorigin="anonymous"></script>
        <style>
            h1{
                text-align: center;
            }
        </style>
    </head>
    <body>
        <h1>Calcule a sua Nota Final</h1>
        <form class="form m-2" action="CalcularMédia2.php" method="POST">
            Nome: <input class="form-control" type="text" name="nome" minlength="3" required>
            Atividades: <input class="form-control" type="number" name="atividades" required>
            Trabalho: <input class="form-control" type="number" name="trabalho" required>
            Teste: <input class="form-control" type="number" name="teste" required>
            Prova: <input class="form-control" type="number" name="prova" required>
            <br>
            <input class="btn btn-primary" type="submit">
        </form>
    </body>
</html>