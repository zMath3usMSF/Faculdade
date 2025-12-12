function carregarArquivoJSON()
{
    fetch("Dados.json", {method: 'get'})
    .then(function(response) {
        response.json().then(function(dados){
            document.getElementById("resp").innerHTML = `
            Nome: ${dados.Nome}<br>
            Descrição: ${dados.Descrição}<br>
            Preço: ${dados.Preço}<br>
            Desconto: ${dados.Desconto}<br>
            Preço Final: ${dados.PreçoFinal}`;
            document.getElementById("resp").className = "alert alert-success";
        })
    })
    .catch(function(error){
        document.getElementById("resp").innerHTML = error
    });
}