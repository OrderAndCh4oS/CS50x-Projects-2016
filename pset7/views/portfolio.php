<h1><?= $title ?></h1>
<p>Cash Balance: $<?= $balance ?></p>
<form action="deposit.php" method="post">
<p>
    <input type="number" step="0.01" name="deposit" placeholder="$">
    <input type="submit" value="Deposit">
</p>
</form>
<table class="table table-striped table-bordered">
    <thead>
        <tr>
            <td>Symbol</td>
            <td>Shares</td>
            <td>Price</td>
            <td>Sell</td>
        </tr>
    </thead>
    <tbody>
        <?php if(count($positions) > 0): ?>

            <?php foreach ($positions as $position): ?>
                <tr>
                    <td><?= htmlspecialchars($position["symbol"]) ?></td>
                    <td><?= htmlspecialchars($position["shares"]) ?></td>
                    <td>$<?= htmlspecialchars(number_format($position["price"], 4, '.', ',')) ?></td>
                    <td>
                        <form action="/sell.php" method="post">
                            <input type="hidden" name="id" value="<?= $position["id"] ?>">
                            <input name="sell" value="Sell" type="submit" class="btn btn-default">
                        </form>
                    </td>
                </tr>
            <?php endforeach ?>
        <?php else: ?>
            <tr>
                <td>N/A</td>
                <td>N/A</td>
                <td>N/A</td>
                <td>N/A</td>
            </tr>
        <?php endif; ?>
    </tbody>
</table>

