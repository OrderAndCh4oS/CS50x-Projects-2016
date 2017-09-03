<?php

    // configuration
    require("../includes/config.php");

    $user = CS50::query("SELECT cash FROM users WHERE id = ? LIMIT 1", $_SESSION['id']);
    $rows = CS50::query("SELECT id, user_id, symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION['id']);
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "id" => $row["id"]
            ];
        }
    }

    // render portfolio
    render("portfolio.php", [
        "title" => "Portfolio",
        "positions" => $positions,
        "balance" => $user[0]["cash"]]
    );

?>
