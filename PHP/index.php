<?php
$conn = new mysqli("127.0.0.1","root","MDwoaixuexi123C++","test","3307");
$conn ->query("SET NAMES 'UTF8'");
//$result = $conn->query(("INSERT INTO gregs_list.my_contacts (first_name) VALUES ('134')"));
//var_dump($result->fetch_all());
$conn->query("DELETE FROM test.student");
$conn->query("DELETE FROM test.pro");
$conn->query("DELETE FROM test.score");
$handle = fopen("student.csv","r+");
fgets($handle);
$lastpro="";
$lastproid = 0;

while($row=fgets($handle))
{
    $arr = explode(",",$row);
    if($lastpro!=$arr[3])
    {
        $result = $conn->query("INSERT INTO test.pro (name) VALUES('{$arr[3]}')");
        //var_dump($result->fetch_all());
        $lastproid = $conn->insert_id;
        $lastpro=$arr[3];
    }
    $result = $conn->query("INSERT INTO test.student (stuid,name,gender,pro) VALUES('$arr[0]','{$arr[1]}','$arr[2]','{$arr[3]}')");
    $result = $conn->query("INSERT INTO test.score (stuid,cscore,mscore,escore) VALUES($arr[0],$arr[4],$arr[5],$arr[6])");
    
} 

?>