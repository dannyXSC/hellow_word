<?php
$handle=fopen("php://stdin","r");
$n=fgets($handle);
$error = 0;
$ans=[];
for($i=0;$i<$n;$i++)
{
    $count=0;
    $row=fgets($handle);
    $inf=explode(" ",$row);
    if($i==0)continue;
    for($j=1;$j<$n;$j++)
    {
        if((int)empty($inf[$j][1])==0)$count++;
    }
    if((int)empty($ans[$count])==0)
    {
        $error=1;
    break;
    }
    $ans[$count]=$inf[0];
}
fclose($handle);
?>