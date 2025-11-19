const executar = () => {
        const fibonacci = (x) => {
        if(x == 0 || x == 1)
            return 1;
        let fm1 = 1, fm2 = 1, fm;
        for(let i = 2; i <= x; i++){
            fm = fm1 + fm2;
            fm2 = fm1;
            fm1 = fm;
        }
        return fm;
    }

    const x = eval(document.getElementById("v1").value);
    let serie = "", i = 0;
    while(i <= x)
    {
        serie += fibonacci(i) + " "; i++;
    }
    document.getElementById("resp").className = "alert alert-success";
    document.getElementById("resp").innerHTML = `Resultado: ${serie}`;
}