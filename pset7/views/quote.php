<h1>Quote for <?= htmlspecialchars($quote['symbol']) ?></h1>
<p><?= htmlspecialchars($quote['name']) ?> <strong>$<?= htmlspecialchars(number_format($quote['price'], 4, '.', ',')) ?></strong></p>
<form action="/buy.php" method="post">
    <input type="number" name="shares" placeholder="Quantity">
    <input type="hidden" name="symbol" value="<?= htmlspecialchars($quote['symbol']) ?>">
    <input type="hidden" name="price" value="<?= htmlspecialchars(number_format($quote['price'], 4, '.', ',')) ?>">
    <input name="buy" value="Buy" type="submit" class="btn btn-default">
</form>
