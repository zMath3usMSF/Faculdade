<!DOCTYPE html>
<html>
    <head>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js" integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI" crossorigin="anonymous"></script>
        <title>Welcome <?php echo $_POST["name"]; ?></title>
        <meta charset="utf-8">
        <style>
            body{
                text-align: center;
            }
        </style>
    </head>
    <body>
        <h1>Welcome: <?php echo $_POST["name"]; ?></h1><br>
        <h1>Your e-mail address is: <?php echo $_POST["email"]; ?></h1>
    </body>
</html>