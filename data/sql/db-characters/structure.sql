DROP TABLE IF EXISTS `evade_logs`;
CREATE TABLE IF NOT EXISTS `evade_logs` (
	`Time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'Time of which the hook was hit',
    `Map` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Map ID for the interaction',
    `VictimX` FLOAT NOT NULL DEFAULT '0' COMMENT 'X coordinate for the evading victim',
    `VictimY` FLOAT NOT NULL DEFAULT '0' COMMENT 'Y coordinate for the evading victim',
    `VictimZ` FLOAT NOT NULL DEFAULT '0' COMMENT 'Z coordinate for the evading victim',
    `VictimO` FLOAT NOT NULL DEFAULT '0' COMMENT 'Orientation of the evading victim',
    `VictimType` TEXT NULL DEFAULT NULL COMMENT 'Type ID of the evading victim',
    `VictimInfo` TEXT NULL DEFAULT NULL COMMENT 'DB GUID, GUID, and name of the evading victim',
    `AttackerX` FLOAT NULL DEFAULT NULL COMMENT 'X coordinate for the attacker',
    `AttackerY` FLOAT NULL DEFAULT NULL COMMENT 'Y coordinate for the attacker',
    `AttackerZ` FLOAT NULL DEFAULT NULL COMMENT 'Z coordinate for the attacker',
    `AttackerO` FLOAT NULL DEFAULT NULL COMMENT 'Orientation of the attacker',
    `AttackerType` TEXT NULL DEFAULT NULL COMMENT 'Type ID of the attacker',
    `AttackerInfo` TEXT NULL DEFAULT NULL COMMENT 'DB GUID, GUID, and name of the attacker',
	`EvadeReason` TEXT NULL DEFAULT NULL COMMENT 'Reasoning for the evade mode'
) COLLATE='utf8mb4_general_ci';
