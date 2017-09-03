<h1><?= $title ?></h1>
<table class="table table-striped table-bordered">
    <thead>
        <tr>
            <td>Created</td>
            <td>Type</td>
            <td>Symbol</td>
            <td>Shares</td>
            <td>Price</td>
        </tr>
    </thead>
    <tbody>
        <?php if(count($history) > 0): ?>

            <?php foreach ($history as $row): ?>
                <tr>
                    <td><?= htmlspecialchars($row['created']) ?></td>
                    <td><?= htmlspecialchars($row['type']) ?></td>
                    <td><?= htmlspecialchars($row["symbol"]) ?></td>
                    <td><?= htmlspecialchars($row["quantity"]) ?></td>
                    <td>$<?= htmlspecialchars(number_format($row["price"], 4, '.', ',')) ?></td>
                </tr>
            <?php endforeach ?>
        <?php else: ?>
            <tr>
                <td>N/A</td>
                <td>N/A</td>
                <td>N/A</td>
                <td>N/A</td>
                <td>N/A</td>
            </tr>
        <?php endif; ?>
    </tbody>
</table>

