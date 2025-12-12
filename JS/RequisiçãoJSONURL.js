function loadRemoteJSON()
{
    var url = "https://dummyjson.com/products/1"

    fetch(url, {method: 'get'})
    .then(function(response) {
        response.json().then(function(data){
            document.getElementById("resp").innerHTML = `
                Product ID: ${data.id}<br>
                Product Title: ${data.title}<br>
                Product Description: ${data.description}<br>
                Product Price: ${data.price}<br>
                Product Discount: Percentage: ${data.discountPercentage}
            `;
            document.getElementById("resp").className = "alert alert-success";
        });
    })
    .catch(function(error) {
        document.getElementById("resp").innerHTML = error
    });
}