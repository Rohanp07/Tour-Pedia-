import React, { useEffect, useState } from 'react'
import { MDBCard, MDBCardBody, MDBInput, MDBCardFooter, MDBValidation, MDBBtn, MDBIcon, MDBSpinner, MDBValidationItem } from 'mdb-react-ui-kit';
import { Link, useNavigate } from 'react-router-dom';

import { useDispatch, useSelector } from 'react-redux';
import { toast } from 'react-toastify';
import { login } from '../redux/features/authSlice';

import { GoogleLogin } from "react-google-login"

const initialState = {
    email: '',
    password: '',
}

const Login = () => {
    const [formValue, setFormValue] = useState(initialState);
    const { email, password } = formValue;

    //loading states,error  and stuff
    const { loading, error } = useSelector((state) => ({ ...state.auth }));


    //redux
    const dispatch = useDispatch();

    //navigator
    const navigate = useNavigate();

    useEffect(() => {
        error && toast.error(error);


    }, [error]);

    const handleSubmit = (e) => {
        e.preventDefault();

        //if we have email and password both then only call login action 
        if (email && password) {
            //we can pass only one argument hence we sent one action 
            //as an object
            dispatch(login({ formValue, navigate, toast }));
        }


    }

    const onInputChange = (e) => {
        let { name, value } = e.target;
        setFormValue({ ...formValue, [name]: value });


    }

    // //google logins
    // const googleSuccess = (res) => {
    //     console.log("SD DNAD DAJAFAFGSVB ASFTAGSBAVSAJSJAKDJN GAK KADJAD ")
    //     console.log(res);
    // }

    // const googleFailure = (err) => {
    //     console.log("wedd isdjsn ")
    //     return toast.error(err.error);
    // }

    return (
        <div style={{ margin: "auto", padding: "15px", maxWidth: "450px", alignContent: "center", marginTop: "120px" }}>
            <MDBCard>
                <MDBIcon fas icon="user-circle" className="fa-2x" />
                <h5>sign In</h5>
                <MDBCardBody>
                    <MDBValidation onSubmit={handleSubmit} noValidate className='row g-3'>
                        <div className='col-md-12'>
                            <MDBValidationItem feedback="Please provide your email" invalid>
                                <MDBInput
                                    label="Email"
                                    type="email"
                                    value={email}
                                    name="email"
                                    onChange={onInputChange}
                                    required
                                />
                            </MDBValidationItem>

                        </div>
                        <div className='col-md-12'>
                            <MDBValidationItem feedback="Please provide your password" invalid >
                                <MDBInput
                                    label="Password"
                                    type="password"
                                    value={password}
                                    name="password"
                                    onChange={onInputChange}
                                    required

                                />
                            </MDBValidationItem>
                        </div>

                        <div className='col-md-12'>

                            <MDBBtn style={{ width: "100%" }} className="mt-2">
                                {loading && (
                                    <MDBSpinner
                                        size="sm"
                                        role="status"
                                        tag='span'
                                        className='me-2'
                                    />
                                )}
                                Login
                            </MDBBtn>
                        </div>

                    </MDBValidation>

                    <br />

                    {/* <GoogleLogin

                        clientId='933080963960-8haoakd4c0md6irjr7r52sib6csde030.apps.googleusercontent.com'

                        render={(renderProps) => (
                            <MDBBtn
                                style={{ width: "100%" }}
                                color="danger"
                                onClick={renderProps.onClick}
                                disabled={renderProps.disabled}


                            >
                                <MDBIcon className='me-2' fab icon='google' /> Google Sign In
                            </MDBBtn>
                        )}
                        onSuccess={googleSuccess}
                        onFailure={googleFailure}
                        cookiePolicy="single_host_origin"
                    /> */}


                </MDBCardBody>
                <br />



                <MDBCardFooter>
                    <Link to="/register">
                        <p>Don't have an account ? sign Up</p>

                    </Link>
                </MDBCardFooter>
            </MDBCard>

        </div>
    )
}

export default Login