class Point{
	constructor(x,y, userData){
		this.x = x;
		this.y = y;
		this.userData = userData;
	}
}

class Rectangle{
	constructor(x,y,w,h){
		this.x=x;
		this.y=y;
		this.w=w;
		this.h=h;
	}
	contains(point){
		if (point.x >=this.x -this.w && 
			point.x <=this.w+this.x && 
			point.y>=this.y-this.h && 
			point.y <= this.y+this.h){
			return true;
		}
		return false
	}
	intersects(range){
		return !((range.x-range.w) > (this.x + this.w) || 
				(range.x+range.w) < (this.x -this.w) ||
				(range.y -range.h) > (this.y +this.h) ||
				(range.y +range.h) < (this.y -this.h))
	}
}

class  QuadTree {
	constructor (boundary,n){
		this.boundary = boundary;  
		this.capacity = n;  
		this.points = []; 
		this.divided = false;
	}
	subdivide(){
		let x=this.boundary.x;
		let y=this.boundary.y;
		let h=this.boundary.h;
		let w=this.boundary.w;

		let NO = new Rectangle(x + w/2,y-h/2,w/2,h/2);
		let NE = new Rectangle(x - w/2,y-h/2,w/2,h/2);
		let SO = new Rectangle(x + w/2,y+h/2,w/2,h/2);
		let SE = new Rectangle(x - w/2,y+h/2,w/2,h/2);
		
		this.hijoNO=new QuadTree(NO,this.capacity);
		this.hijoNE=new QuadTree(NE,this.capacity);
		this.hijoSO=new QuadTree(SO,this.capacity);
		this.hijoSE=new QuadTree(SE,this.capacity); 

		this.divided=true;
	
	}
	
	insert(point){

        if (!this.boundary.contains(point)){
				return false;
			}
        if (this.points.length < this.capacity){
			this.points.push(point);
			return true;
		}else{
			if(!this.divided){
				this.subdivide();
			}
			this.hijoNO.insert(point);
			this.hijoNE.insert(point);
			this.hijoSO.insert(point);
			this.hijoSE.insert(point);
		}
	}
	show (){
		stroke (255);
		strokeWeight(1);
		noFill();
		rectMode(CENTER);
		rect(this.boundary.x,this.boundary.y,this.boundary.w*2,this.boundary.h*2);
		if (this.divided){
			this.hijoNO.show();
			this.hijoNE.show();
			this.hijoSO.show();
			this.hijoSE.show();
		}
		for ( let p of this.points){
			strokeWeight(4);
			point (p.x,p.y);
		}
	}
}

