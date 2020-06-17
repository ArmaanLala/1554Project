const mathjs = require("mathjs");

const A = mathjs.matrix([
    [0, 0, 0, 0, 1, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 0, 1, 0],
    [0, 0, 0, 0, 0, 0, 1, 0, 1],
    [0, 0, 0, 0, 1, 0, 0, 1, 0],
    [1, 0, 0, 1, 0, 0, 0, 0, 1],
    [1, 1, 0, 0, 0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 1, 0, 0, 0, 0],
]);

var B = mathjs.matrix([
    [0, 0, 0, 0, 1, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 0, 1, 0],
    [0, 0, 0, 0, 0, 0, 1, 0, 1],
    [0, 0, 0, 0, 1, 0, 0, 1, 0],
    [1, 0, 0, 1, 0, 0, 0, 0, 1],
    [1, 1, 0, 0, 0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 1, 0, 0, 0, 0],
]);

global.clicked =  function() {
    B = mathjs.matrix([
        [0, 0, 0, 0, 1, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 0, 1, 0, 1],
        [0, 0, 0, 0, 1, 0, 0, 1, 0],
        [1, 0, 0, 1, 0, 0, 0, 0, 1],
        [1, 1, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0, 1, 0, 0, 0],
        [0, 1, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 1, 0, 0, 0, 0],
    ]);

    var btn = document.getElementById('value').value;
    var i;
    // console.log(btn)

    // Calculates the Final Matrix
    for (i = 2; i < btn; i++) {
        B = mathjs.multiply(A, B);
    }


    var sum = 0;
    var rowSums = [0, 0, 0, 0, 0, 0, 0, 0, 0];

    //Sums up the matrix and the rows
    B.forEach(function (value, index, matrix) {
        sum = sum + value;
        rowSums[index[0]] = rowSums[index[0]] + value;
    });

    // I am too lazy to add a better way to do this
    var all = document.getElementById("a");
    all.textContent = sum;
    var zero = document.getElementById("0");
    zero.textContent = rowSums[0];
    var one = document.getElementById("1");
    one.textContent = rowSums[1];
    var two = document.getElementById("2");
    two.textContent = rowSums[2];
    var three = document.getElementById("3");
    three.textContent = rowSums[3];
    var four = document.getElementById("4");
    four.textContent = rowSums[4];
    var five = document.getElementById("5");
    five.textContent = rowSums[5];
    var six = document.getElementById("6");
    six.textContent = rowSums[6];
    var seven = document.getElementById("7");
    seven.textContent = rowSums[7];
    var eight = document.getElementById("8");
    eight.textContent = rowSums[8];

}
