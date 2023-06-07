<html>
    <head>
        <title>Practice 4</title>
    </head>
    <body>
        <p>Here is the Multiplcation table for <?php echo $_POST["num"]; ?>: </p>
        <?php
        $end = $_POST["num"];
        echo "<style> tr, td {padding: 10px;}</style>";
        echo "<table border =\"1\" style = 'border-collapse: collapse'>";
        for ($r = 0; $r <= $end; $r++) {   
            echo "<tr> \n"; 
            for ($c = 0; $c <= $end; $c++) {    
                if (($r == 0) and ($c == 0)){  
                    $p = "";
                }
                else if ($r == 0) { 
                    $p = $c;
                }
                else if ($c == 0) {
                    $p = $r;
                }
                else {
                    $p = $c * $r; 
                }
                echo "<td>$p</td> \n"; 
            }
            echo "</tr>"; 
        }
        echo "</table>" 
        ?>
    </body>
</html>
