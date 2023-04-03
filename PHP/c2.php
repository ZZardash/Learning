<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <div>
        <?php
            //include "c1.php"; //Resulting with WARNING
            //require "c1.php"; //Resulting with ERROR
            //Prettify the array
            /*
            function prettyArray($array){
                echo "<pre>";
                print_r($array);
                echo "</pre>";
            }
            $array = [
                1 => "a",
                2 => "b",
                3 => "c",
                4 => "d",
                5 => "e",
            ];           
            prettyArray($array);
            prettyArray(array_chunk($array, 2)); 
            $array = [
                1 => "e",
                2 => "f",
                3 => "g",
                4 => "r",
                5 => "h",
            ];           
            print("<br><br>-----ERROR HANDLING----<br>");
            */
            use PDO;
            
            try{
                $db = new PDO('mysql:host=localhost; dbname=my_db', 'root', ''); //(host,dbname,username,password)
                $query = "SELECT * FROM users";
                $stmt = $db -> query($query); //Injecting query in db
                
                foreach($stmt->fetchAll(PDO::FETCH_OBJ) as $user){
                    echo "<pre>";
                    var_dump($user);
                    echo "<\pre>";
                }
            }
            catch(Exception $e){
                echo $e -> getMessage();
                //var_dump($stmt->fetchAll()); //Fetch all data
                //We use (prepare) method for avoiding sql injection
                /*foreach($stmt->fetchAll(PDO::FETCH_OBJ) as $user){
                    echo "<pre>";
                    var_dump($user);
                    echo "<\pre>";
                }*/
                /*
                $email = "sertacyurtaslan123@gmail.com";
                $name = "Sertaç Yurtaslan";
                $createdAt = date("Y-m-d H:m:i", strtotime("21/11/2022 9:00AM"));

                //Inserting data with prepare() and execute()
                $query = "INSERT INTO users(email, full_name, created_at) values(?,?,?)";
                $stmt = $db -> prepare($query);
                $stmt -> execute([$email, $full_name, $createdAt]);//Using execute for formatting prepared query
                //$id = $db -> lastInsertId();
                */
                
            }

            var_dump($db);//Check if db connected


        ?>
    </div>
</body>
<style>
    div{
        color:aquamarine
    }
    body{
        background-color: black;
    }
</style>
</html>