let valores = [];

const addValor = (x) =>{
    valores.push([valores.length + 1, x]);
}

const media = () => {
    let soma = 0;
    for (let x of valores)
        soma += x[1];
    return soma / valores.length;
}

const drawBasic = () => {
    var data = new google.visualization.DataTable();
    data.addColumn('number', 'Pos');
    data.addColumn('number', 'X');
    data.addRows(valores);
    var options = { hAxis: { title: 'Posicao'}, vAxis: { title: 'Valor de X' } };

    var chart = new google.visualization.LineChart(document.getElementById('chart_div'));

    chart.draw(data, options);
}

const executar = () => {
    const x = eval(document.getElementById("v1").value);
    addValor(x);
    google.charts.load('current', {packages: ['corechart', 'line']});
    google.charts.setOnLoadCallback(drawBasic);
    document.getElementById("resp").className = "alert alert-warning";
    document.getElementById("resp").innerHTML = `Media: ${media()}`;
}
