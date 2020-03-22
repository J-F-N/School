<?php
/**
 * Created by PhpStorm.
 * User: MKochanski
 * Date: 7/24/2018
 * Time: 3:07 PM
 */
require_once 'config.inc.php';
// Get Customer Number
$id = $_GET['id'];
if ($id === "") {
    header('location: list_customers.php');
    exit();
}
if ($id === false) {
    header('location: list_customers.php');
    exit();
}
if ($id === null) {
    header('location: list_customers.php');
    exit();
}
?>
<html>
<head>
    <title>Sample PHP Database Program</title>
    <link rel="stylesheet" href="base.css">
</head>
<body>
<?php
require_once 'header.inc.php';
?>
<div>
    <h2>Update Org</h2>
    <?php

    // Create connection
    $conn = new mysqli($servername, $username, $password, $database, $port);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $fullName = $_POST['fullName'];
        if ($fullName === null)
            echo "<div><i>Specify a new name</i></div>";
        else if ($fullName === false)
            echo "<div><i>Specify a new name</i></div>";
        else if (trim($fullName) === "")
            echo "<div><i>Specify a new name</i></div>";
        else {
            /* perform update */
            $sql = "UPDATE Organization SET fullName = ? WHERE organizationId = ?";
            $stmt = $conn->stmt_init();
            if (!$stmt->prepare($sql)) {
                echo "failed to prepare";
            } else {
                $stmt->bind_param('ss', $fullName,$id);
                $stmt->execute();
                $conn->commit();
            }
        }
    }

    /* Refresh the Data */
    // $sql = "SELECT organizationId, fullName, phoneNumber, email FROM Organization O " .
    //     "WHERE organizationId = ?";
    $sql = "SELECT fullname,phonenumber,email,address,city,state,postalcode FROM Organization  " .
    "INNER JOIN (OwnerHistory INNER JOIN (LandParcel INNER JOIN Location
    ON LandParcel.geotag = Location.geotag)
    ON OwnerHistory.landParcelId = LandParcel.landParcelId)
    ON Organization.organizationId = OwnerHistory.organizationId WHERE Organization.organizationId = $id";
    $stmt = $conn->stmt_init();
    if (!$stmt->prepare($sql)) {
        echo "failed to prepare";
    }
    else {
        // $stmt->bind_param('s',$id);
        $stmt->execute();
        $stmt->bind_result($fullName,$phoneNumber,$email,$address,$city,$state,$postalcode);
        ?>
        <form method="post">
            <input type="hidden" name="id" value="<?= $id ?>">
        <?php
        while ($stmt->fetch()) {
            echo '</a><br>' . '<a href="show_customer.php?id='  . $organizationId . '">' . $fullName . '</a><br>' .
             $phoneNumber . '</a><br>' . $email . '</a><br>' . $address . '</a><br>' . $city . '</a><br>' . $state . '</a><br>' . $postalcode;
        }
    ?><br><br>
            New Name: <input type="text" name="fullName">
            <button type="submit">Update</button>
        </form>
    <?php
    }

    $conn->close();

    ?>
</>
</body>
</html>
