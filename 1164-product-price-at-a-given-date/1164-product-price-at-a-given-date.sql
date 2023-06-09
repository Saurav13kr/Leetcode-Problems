# Write your MySQL query statement below
with cte as
(
	select	product_id,
			new_price,
			change_date,
			rank() over(partition by product_id order by change_date desc) as changeDate_rank
	from products
	where change_date <= '2019-08-16'
)

select distinct p.product_id, ifnull(t.new_price, 10) as price
from products as p
left join cte as t
on p.product_id = t.product_id
and changeDate_rank = 1
order by price desc