<!DOCTYPE html>
<html>
    <head>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js" integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI" crossorigin="anonymous"></script>
        <title>Exemplo de Requisição PHP usando Método POST</title>
        <meta charset="utf-8">
    </head>
    <body>
        <h1>Exemplo de Requisição PHP usando Método POST</h1>
        <form class="form m-2" action="welcome.php" method="POST" >
            Name: <input class="form-control" type="text" name="name" minlength="3" required><br>
            E-mail: <input class="form-control" type="text" name="email" minlength="6" required><br>
            <input class="form-control" type="submit">
        </form>
    </body>
</html>