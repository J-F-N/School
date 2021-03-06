<?php
/**
 * Created by PhpStorm.
 * User: MKochanski
 * Date: 7/24/2018
 * Time: 3:07 PM
 */
require_once 'config.inc.php';

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
        <h2>Search Results</h2>
<?php
// Create connection
    $conn = new mysqli($servername, $username, $password, $database, $port);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    if (isset($_POST['submit-search'])) {
        $search = mysqli_real_escape_string($conn, trim($_POST['search']));
        $sql = "SELECT organizationId,fullName FROM Organization WHERE fullName LIKE '%$search%' ORDER BY fullName";
        $stmt = $conn->stmt_init();
        if (!$stmt->prepare($sql)) {
            echo "failed to prepare";
        }
        else {
            $stmt->execute();
            $stmt->bind_result($customerNumber,$customerName);
            echo "<ul>";
            while ($stmt->fetch()) {
                echo '<li><a href="show_customer.php?id='  . $customerNumber . '">' . $customerName . '</a></li>';
            }
            echo "</ul>";
        }
    }


