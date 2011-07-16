<?php

/**
 * @file
 * Redis cache backend using Predis PHP library as Redis client.
 */

// No autoloader is here during early bootstrap phases.
if (!class_exists('Redis_Client_Predis')) {
  $local_redis_path = dirname(__FILE__) . '/lib/Redis';
  require_once $local_redis_path . '/Client/Interface.php';
  require_once $local_redis_path . '/Client.php';
  require_once $local_redis_path . '/Client/Predis.php';
  require_once $local_redis_path . '/Cache/Predis.php';
}

// Register our specific client.
if (!Redis_Client::hasClient()) {
  Redis_Client::setClient(new Redis_Client_Predis);
}