<?php

    // configuration
    require("../includes/config.php");

    if(!preg_match("/^\d+$/", $_POST["shares"])) {
        apologize("You must only purchase whole stocks");
    }

    $cost = $_POST["shares"] * $_POST["price"];
    $row = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION['id']);

    if($row[0]['cash'] < $cost) {
        apologize("Not enough funds available to complete purchase");
    }

    $result = CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?)".
                "ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",
                $_SESSION['id'], strtoupper($_POST["symbol"]), $_POST["shares"]);

    if($result != 0) {
        CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION['id']);
        logHistory($_POST['symbol'], $_POST['price'], $_POST['shares'], 'purchased', $_SESSION['id']);
        render("bought.php", ["shares" => $_POST["shares"], "symbol" => $_POST["symbol"], "cost" => $cost]);
    }

    apologize("There was an error buying the stock");

?>
