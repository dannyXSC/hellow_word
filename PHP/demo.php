<?php
$conn = new mysqli("127.0.0.1","root","MDwoaixuexi123C++","test","3307");
$conn ->query("SET NAMES 'UTF8'");

$result = $conn->query("SELECT student.stuid AS '学号',student.name AS '姓名',student.gender AS '性别',
score.cscore AS '语文成绩',pro.name AS'专业' FROM test.student 
LEFT JOIN test.score on student.stuid=score.stuid 
LEFT JOIN test.pro  on  student.pro=pro.name
WHERE student.name = '张三'");
while($row=$result->fetch_object())
{
    var_dump($row);
}