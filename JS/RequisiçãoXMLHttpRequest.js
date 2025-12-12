carregarImagens()
function carregarImagens(){

    var xmlHttpRequest = new XMLHttpRequest();
    var url = "https://dog.ceo/api/breeds/image/random"

    xmlHttpRequest.open("GET", url, true);

    xmlHttpRequest.onreadystatechange = function() {
        if (xmlHttpRequest.readyState == 3) {
            console.log('Carregando o conteúdo');
        }
        if (xmlHttpRequest.readyState == 4) {

            var jsonResponse = JSON.parse(xmlHttpRequest.responseText);

            console.log('Requisição Finalizada');
            console.log('Resultado da Requisição: ' + jsonResponse);
            console.log('Resultado da Requisição: ' + jsonResponse.message);

            var imgDog = document.getElementById("img_dog");
            imgDog.src = jsonResponse.message;
        }
    };

    xmlHttpRequest.send(null);

}