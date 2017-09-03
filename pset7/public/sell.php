<?php

    // configuration
    require("../includes/config.php");

    $row = CS50::query("SELECT id, user_id, symbol, shares FROM portfolios WHERE user_id = ? AND id = ?", $_SESSION['id'], $_POST["id"]);
    if($row) {
        $stock = lookup($row[0]["symbol"]);
        CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION['id'], $row[0]["symbol"]);
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?",$row[0]["shares"] * $stock["price"], $_SESSION['id']);
        logHistory($row[0]["symbol"], $stock["price"], $row[0]["shares"], 'sold', $_SESSION['id']);

        render("sold.php", [
            "symbol" => $row[0]["symbol"],
            "total" => $row[0]["shares"] * $stock["price"]
        ]);
    }

    apologize("There was an error selling the stock");


?>
