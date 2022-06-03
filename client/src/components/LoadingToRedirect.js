import React, { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';


const LoadingToRedirect = () => {
    const [count, setCount] = useState(5);
    const navigate = useNavigate();

    //this states count will decrease by 1
    //every second and since initial state is 5 
    //after 5 seconds unathprized user willl be
    //redirected to login

    useEffect(() => {
        const interval = setInterval(() => {
            setCount((currCount) => --currCount);

        }, 1000);

        count === 0 && navigate("/login");

        return () => clearInterval(interval);

    }, [count, navigate]);

    return (
        <div style={{margin:"100px"}} >
            <h5>Redirecting you in {count} seconds</h5>
        </div>
    )
}

export default LoadingToRedirect