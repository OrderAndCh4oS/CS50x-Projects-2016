<?php

    // configuration
    require("../includes/config.php");

    if(!preg_match("/^\d+\.\d\d$/", $_POST["deposit"])) {
        apologize("Enter a decimal with two floating points");
    }

    $result = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST['deposit'], $_SESSION['id']);
    if($result != 0) {
        render("deposit.php");
    }

    apologize("There was an error adding funds");

?>
