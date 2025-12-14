<?php
    function ObterMedia()
    {
        $media = 0;

        $media += $_POST["atividades"];
        $media += $_POST["trabalho"];
        $media += $_POST["teste"];
        $media += $_POST["prova"];

        return $media / 4;
    }

    $media = ObterMedia();
    if($media >= 5)
    {
        echo $_POST["nome"] . ", sua nota final foi: " . ObterMedia() . ". Parabéns, você foi aprovado(a)";
    }
    else
    {
        echo $_POST["nome"] . ", sua nota final foi: " . ObterMedia() . ". Você foi reprovado(a)";
    }
?>