"use strict";

var TABLE = function()
{
    this.tbl = {};
};

module.exports = TABLE;

TABLE.prototype.init = function()
{
    this.tbl = {};
};

TABLE.prototype.check = function( key )
{
    return this.tbl[ key ] ? true : false;
};

TABLE.prototype.add = function( key ) 
{
    this.tbl[ key ] = 1;
};

TABLE.prototype.dump = function( name )
{

};

TABLE.prototype.load = function( name )
{

};